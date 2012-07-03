# Series Test Example

## Important Classes
  * SIMDAQThread
  * AnalysisThreadChain

## Summary

This example is similar to the simulator and histogramming examples, except there are a large number of analysis threads.  Data blocks for ADC, channel, and timestamps are simply passed down the line from one thread to the next.  A single histogram of ADC values is kept by each thread and all are displayed in a window.

The number of threads is specified in the calls to the `make_xml*.py` scripts in the pro file, as well as the `NUM_ANALYSIS_THREADS` constant in `main.cpp`.  These numbers must match or there will be run-time errors.

## Application Graph

This graph of the threads and data connections was produced using the script `$GRIFDIR/util/draw_app_graph.py`.

<center><img src="app.svg" alt="Series Test GRIF Application" title="Series Test GRIF Application" /></center>