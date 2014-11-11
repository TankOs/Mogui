#include <mogui/element_selector.hpp>

namespace mog {

void ElementSelector::set_name( const std::string& name ) {
  _name = name;
}

const std::string& ElementSelector::get_name() const {
  return _name;
}


}
