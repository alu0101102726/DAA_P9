#include "node.hpp"


Node::Node(float newValue, float newUpperBound):
  partialSol() {
    upperBound = newUpperBound;
    value = newValue;
    is_prun = false;
    visited = false;
}

float Node::getUpperBound() {
  return upperBound;
}

void Node::setUpperBound(float newUpperBound) {
  upperBound = newUpperBound;
}

float Node::getValue() {
  return value;
}

void Node::setValue(float newValue) {
  value = newValue;
}

bool Node::isPrun() {
  return is_prun;
}

void Node::setPruned(bool newValue) {
  is_prun = newValue;
}

bool Node::isVisited() {
  return visited;
}

void Node::setVisited(bool newValue) {
  visited = newValue;
}

std::vector<int> Node::getVector() {
  return partialSol;
}

void Node::setVector(std::vector<int> newVect) {
  partialSol = newVect;
}

void Node::addChilds(int newNode) {
  partialSol.push_back(newNode);
}

std::ostream& operator<<(std::ostream& os, Node otherNode) {
  os << " Nodo [" << otherNode.getVector()[0] << "]: " << otherNode.getValue() << "\n";
  return os;
}
