#pragma once

#include <string>

namespace mog {

class ElementSelector {
  public:
    void set_name( const std::string& name );
    const std::string& get_name() const;

  private:
    std::string _name;
};

}

/** @class mog::ElementSelector
 * Used for filtering elements by certain properties.
 */
