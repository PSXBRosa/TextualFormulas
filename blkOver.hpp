#pragma once
#include "blkBlock.hpp"

namespace blk {
  expr over(expr op1, expr op2);

  class Over : public Block {
  private:
    
    expr op1;
    expr op2;

    // These functions make auxiliary size and ref computation for the
    // resulting block, from the two operands. Use them as arguments
    // to the conctruction of super class Block in the Beside
    // constructor.
    static int compute_width     (expr op1, expr op2){
      return compute_ref_width(op1, op2) + std::max(op1 -> get_ref_width(), op2 -> get_ref_width());
    }

    static int compute_height    (expr op1, expr op2){
      return (op1 -> get_height()) + (op2 -> get_height());
    }

    static int compute_ref_width (expr op1, expr op2){
      return std::max(op1 -> get_ref_width(), op2 -> get_ref_width());
    }

    static int compute_ref_height(expr op1, expr op2){
      return op1 -> get_ref_height();
    }
    
  public:
    
    Over(expr op1, expr op2);
    virtual ~Over() {}
    virtual void print_inbounds_line(std::ostream& os, int line) const override;
  };
}
