#include "blkBlock.hpp"
#include "blkBeside.hpp"

blk::expr blk::beside(blk::expr op1, blk::expr op2){
  return std::make_shared<blk::Beside> (op1, op2); 
}

blk::Beside::Beside(expr op1, expr op2) :
  blk::Block(compute_width(op1, op2),
             compute_height(op1, op2),
             compute_ref_width(op1, op2),
             compute_ref_height(op1,op2)),
  op1(op1), op2(op2) {}

void blk::Beside::print_inbounds_line(std::ostream& os, int line) const{
  op1 -> print_line(os, line);
  op2 -> print_line(os, line);
}
