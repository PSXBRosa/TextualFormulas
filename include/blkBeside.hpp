#pragma once
#include "blkBlock.hpp"

namespace blk {
  expr beside(expr op1, expr op2);

  class Beside : public Block {
  private:

    expr op1;
    expr op2;

    // These functions make auxiliary size and ref computation for the
    // resulting block, from the two operands.
    static int compute_width     (expr op1, expr op2){
      return (op1 -> get_width()) + (op2 -> get_width());
    }

    static int compute_height    (expr op1, expr op2){
      return compute_ref_height(op1, op2) + std::max((op1 -> get_height()) - (op1 -> get_ref_height()),
                                                     (op2 -> get_height()) - (op2 -> get_ref_height()));
    }

    static int compute_ref_width (expr op1, expr op2){
      return op1 -> get_ref_width();
    }

    static int compute_ref_height(expr op1, expr op2){
      return std::max(op1 -> get_ref_height(), op2 -> get_ref_height());
    }

  public:

    Beside(expr op1, expr op2);
    virtual ~Beside() {}
    virtual void print_inbounds_line(std::ostream& os, int line) const override;
  };
}
