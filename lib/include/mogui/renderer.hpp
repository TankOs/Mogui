#pragma once

#include <mogui/drawable_container.hpp>

namespace mog {

class Renderer : public DrawableContainer {
  public:
    virtual ~Renderer() = default;

  private:
};

}

/** @class mog::Renderer
 * Abstract base class for renderers.
 */
