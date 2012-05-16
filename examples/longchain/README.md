# Long Analysis Chain Test Example

## Important Classes
  * SIMDAQThread
  * AnalysisThread**

## Summary

This example is similar to the histogramming example, except there are 50 analysis threads.  Data blocks for ADC, channel, and timestamps are simply passed down the line from one thread to the next.  A single histogram of ADC values is kept by each thread and all are displayed in a window.
