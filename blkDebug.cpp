#include "blkBlock.hpp"
#include "blkDebug.hpp"

blk::expr blk::debug(char label, int width, int height, int ref_width, int ref_height){
  return std::make_shared<const blk::Debug> (label, width, height, ref_width, ref_height);
}

blk::Debug::Debug(char label, int width, int height, int ref_width, int ref_height) : blk::Block(width, height, ref_width, ref_height), label(label) {}

