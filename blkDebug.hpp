#pragma once
#include "blkBlock.hpp"

namespace blk {
  // This is a factory that builds a debug block.
  expr debug(char label, int width, int height, int ref_width, int ref_height);

  class Debug : public Block {
  private:
    
    char label;
    
  public:

    Debug(char label, int width, int height, int ref_width, int ref_height);
    virtual ~Debug() {}

    // This one has to be implemented.
    virtual void print_inbounds_line(std::ostream& os, int line) const override{

    if(line != 0){os << std::string(get_width(), label);}
    else{os << std::string(get_ref_width(), label) << '#' << std::string(get_width() - get_ref_width() - 1, label);} 
    };

  };
}
