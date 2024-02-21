#include "Logger.hpp"

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>

void Logger::addItem(Level l, const std::string & m) {
  // TODO implement Logger::addItem
  _items.push_back(std::make_tuple(l,m));
}

std::string Logger::reportByAdded() const {
  // TODO Logger::reportByAdded
  std::string output = "**** report_by_added ****\n";
  if(!_items.empty()){
    for(const auto &tuple : _items){
      output += std::get<1>(tuple) + "\n";
    }
  }
  
  return output;
}

std::string Logger::reportByLevel() const {
  // TODO Logger::reportByLevel
  return "TODO Logger::reportByLevel";
}

