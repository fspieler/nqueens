#ifndef CCCT_DEBUG_INCLUDE_GUARD
#define CCCT_DEBUG_INCLUDE_GUARD

#include <iostream>
#include <map>
#include <utility>

namespace ccct_debug {

void display()
{}

template<typename T>
void display(T last)
{
  std::cerr << last;
}

template<typename T, typename... Ts>
void display(T first, Ts... rest)
{
  std::cerr << first << ", ";
  display(rest...);
}

} // namespace fred_debug

#define DEBUG(x) std::cerr << "line " << __LINE__  << " " << __FILE__ << " | " << #x << " -> " << x << std::endl;

#define DEBUGF(f, ... )                                   \
  std::cerr << "line " <<__LINE__ << " " << __FILE__ " | "                 \
            << #f << "(" << #__VA_ARGS__ << ") -> "       \
            << #f << "(";                                 \
  ccct_debug::display(__VA_ARGS__);                       \
  std::cerr << ") = " << f(__VA_ARGS__) << std::endl;

#include <vector>

template<typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v)
{
  os << "[";
  bool flag = false;
  for(auto e : v) {
    flag = true;
    os << e << ", ";
  }

  os << (flag ? "\b\b]" : " ]");
  return os;
}

template<typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<bool>& v)
{
  os << "[";
  bool flag = false;
  for(bool e : v) {
    flag = true;
    os << e << ", ";
  }

  os << (flag ? "\b\b]" : " ]");
  return os;
}

template<typename T,typename U>
std::ostream& operator<< (std::ostream& os, const std::map<T,U>& m)
{
  os << "{" ;
  for(const auto& kv: m)
  {
    os << "(" << kv.first << ", " << kv.second << "), "; 
  }
  os << "\b\b}";
  return os;
}

template<typename T,typename U>
std::ostream& operator<< (std::ostream& os, const std::pair<T,U>& p)
{
  os << "(" << std::get<0>(p) << ", " << std::get<1>(p) << ")"; 
  return os;
}

#endif //CCCT_DEBUG_INCLUDE_GUARD
