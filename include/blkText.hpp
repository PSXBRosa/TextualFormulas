#pragma once
#include "blkBlock.hpp"

namespace blk {

  enum align {
    center = 0,
    right  = 1,
    left   = 2,
  };

  class Text : public Block {

    public:
      Text(std::string label, int pos);
      ~Text() {}

    private:
      std::string label;
      int pos;
      int compute_rel_width(std::string label, int pos){
        switch(pos){
          case align::left:
            return 0;
          case align::right:
            return label.size() - 1;
          case align::center:
            return label.size() / 2;
        }
        return 0;
      }

    virtual void print_inbounds_line(std::ostream& os, int line) const;

  };

  expr text(std::string label, int pos);
  expr text(std::string label);
  expr from_value(double value);
}
