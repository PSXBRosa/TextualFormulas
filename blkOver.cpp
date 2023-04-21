#include "blkBlock.hpp"
#include "blkOver.hpp"

blk::expr blk::over(blk::expr op1, blk::expr op2){
  return std::make_shared<blk::Over> (op1, op2);
}

blk::Over::Over(expr op1, expr op2) :
  blk::Block(compute_width(op1, op2),
             compute_height(op1, op2),
             compute_ref_width(op1, op2),
             compute_ref_height(op1,op2)),
  op1(op1), op2(op2) {}

void blk::Over::print_inbounds_line(std::ostream& os, int line) const{
  int lpad;
  int rpad;
  int ref = (op1 -> get_height()) - (op1 -> get_ref_height());
  if(line < ref){
    lpad = std::max((op2 -> get_ref_width()) - (op1 -> get_ref_width()), 0);
    rpad = std::max((op2 -> get_width() - (op2 -> get_ref_width())) -
                   ((op1 -> get_width() - (op1 -> get_ref_width()))),0);
    os << std::string(lpad, ' ');
    op1 -> print_line(os, line);
    os << std::string(rpad, ' ');
  }
  else{
    lpad = std::max((op1 -> get_ref_width()) - (op2 -> get_ref_width()), 0);
    rpad = std::max((op1 -> get_width() - (op1-> get_ref_width())) -
                   ((op2 -> get_width() - (op2 -> get_ref_width()))),0);
    os << std::string(lpad, ' ');
    op2 -> print_line(os, (line - ref) - (op2 -> get_ref_height()));
    os << std::string(rpad, ' ');    
  }
}
