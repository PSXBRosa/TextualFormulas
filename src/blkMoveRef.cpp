#include "blkMoveRef.hpp"

blk::expr blk::move_ref(blk::expr op1, int rw, int rh){
  return std::make_shared<MoveRef>(op1, rw, rh);
}

blk::MoveRef::MoveRef(blk::expr op1, int rw, int rh):
  blk::Block(op1 -> get_width(), op1 -> get_height(), rw, rh),
  op1(op1), rw(rw), rh(rh) {}
