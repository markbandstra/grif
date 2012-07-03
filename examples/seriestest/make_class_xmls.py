from __future__ import print_function
import sys
import os

def format(path):
    return path.replace('\\','/')

grif_root = ".."
grif_root = os.path.abspath(grif_root)

try:
  project_dir = sys.argv[1]
  num_threads = int(sys.argv[2])
except:
  print("usage: python setup.py /path/to/project/dir number_of_threads")
  sys.exit(-1)

project_dir = os.path.abspath(project_dir)
# app_xml = format(os.path.join(project_dir, "XML/app/APP.XML"))
classes_xml_dir = format(os.path.join(project_dir, "XML/classes"))

print("-"*20)
print("Class XML file directory: {0}".format(classes_xml_dir))
print("Removing analysis thread XML files")
try:
    os.system("ls -lh "+classes_xml_dir)
except:
    print("Class XML directory not available")
    sys.exit(-1)
try:
    os.system("rm "+classes_xml_dir+"/A*.XML")
except:
    print("Unable to delete analysis thread XML files")
    sys.exit(-1)

def thread_str(thread_num):
    return str('%02d' % thread_num)

for thread_num in range(num_threads):
    class_xml = format(os.path.join(classes_xml_dir, 'A'+thread_str(thread_num)+'.XML'))
    print("Writing class XML file: {0}".format(class_xml))
    xmlfile = file(format(class_xml), 'w')

    print('<?xml version="1.0"?>', file=xmlfile)
    print('<class>', file=xmlfile)
    print('  <Name name = \"A'+thread_str(thread_num)+'\" />', file=xmlfile)
    print('  <Header hname = \"AnalysisThreadSeries.h\" />', file=xmlfile)
    print('  <Info cname = \"AnalysisThreadSeries\" isdaq = \"false\" />', file=xmlfile)
    print('  <DataBlocks>', file=xmlfile)
    for data in ['ADCOutput', 'CHAN', 'TS']:
        print('    <Data block = \"'+data+'\" />', file=xmlfile)
    print('  </DataBlocks>', file=xmlfile)
    print('</class>', file=xmlfile)
