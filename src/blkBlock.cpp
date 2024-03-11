#include "blkBlock.hpp"
#include <iomanip>

blk::Block::Block(int width, int height, int ref_width, int ref_height) : width(width), height(height), ref_width(ref_width), ref_height(ref_height) {}

int blk::Block::min_line() const{
  return - ref_height;
}

int blk::Block::max_line() const{
  return height - ref_height; 
}

std::ostream& blk::operator<<(std::ostream& os, blk::expr e){
  for(int l = e->min_line(); l < e->max_line(); ++l){
    os << std::setw(3) << l << ":";
    (e->print_line(os, l));
    os << std::endl;
  }
  return os;
}

void blk::Block::print_line(std::ostream& os, int line) const{
  if(line < min_line() || line >= max_line()){
    os << std::string(width, ' ');
  } else {
    print_inbounds_line(os, line);
  }
}

int blk::Block::get_width() const{
  return width;
}

int blk::Block::get_height() const{
  return height;
}

int blk::Block::get_ref_width() const{
  return ref_width;
}

int blk::Block::get_ref_height() const{
  return ref_height;
}


