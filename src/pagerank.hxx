#pragma once
#include <vector>
#include <utility>

using std::vector;
using std::move;




// PAGERANK-OPTIONS
// ----------------

template <class T>
struct PagerankOptions {
  int repeat;
  int toleranceNorm;
  int monolithicIterations;
  T   damping;
  T   tolerance;
  int maxIterations;

  PagerankOptions(int repeat=1, int toleranceNorm=1, int monolithicIterations=0, T damping=0.85, T tolerance=1e-6, int maxIterations=500) :
  repeat(repeat), toleranceNorm(toleranceNorm), monolithicIterations(monolithicIterations), damping(damping), tolerance(tolerance), maxIterations(maxIterations) {}
};




// PAGERANK-RESULT
// ---------------

template <class T>
struct PagerankResult {
  vector<T> ranks;
  int   iterations;
  float time;

  PagerankResult(vector<T>&& ranks, int iterations=0, float time=0) :
  ranks(ranks), iterations(iterations), time(time) {}

  PagerankResult(vector<T>& ranks, int iterations=0, float time=0) :
  ranks(move(ranks)), iterations(iterations), time(time) {}
};
