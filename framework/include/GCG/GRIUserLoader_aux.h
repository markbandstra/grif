  if (object_name == "LBIMA1") {
    p = new LBImAnalysisThread();
    return p;
  }

  if (object_name == "LBIMDAQ1") {
    p = new LBImDAQThread();
    return p;
  }

