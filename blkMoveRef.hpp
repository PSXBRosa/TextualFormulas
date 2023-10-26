#pragma once
#include "blkBlock.hpp"

namespace blk {
  expr move_ref(expr op1, int rw, int rh);

  class MoveRef : public Block {
  private:

    expr op1;
    int rw;
    int rh;

  public:

    MoveRef(expr op1, int rw, int rh);
    virtual ~MoveRef() {}
    virtual void print_inbounds_line(std::ostream& os, int line) const override{
      op1 -> print_inbounds_line(os, line + (get_ref_height() - op1->get_ref_height()));
    }
  };
}
