#pragma once
#include "blkBlock.hpp"

namespace blk {

  struct align {
    static const int center = 0;
    static const int right  = 1;
    static const int left   = 2;
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
          case 2:
            return 0;
          case 1:
            return label.size() - 1;
          case 0:
            return label.size() / 2;
        }
        return 0;
      }

    virtual void print_inbounds_line(std::ostream& os, int line) const;

  };

  expr text(std::string label, int pos);
  expr text(std::string label);
 }
