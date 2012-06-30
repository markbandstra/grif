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
  print(len(sys.argv))
  sys.exit(-1)

project_dir = os.path.abspath(project_dir)
app_xml = format(os.path.join(project_dir, "XML/app/APP.XML"))
# classes_xml_dir = format(os.path.join(project_dir, "XML/classes"))

print("-"*20)
print("Writing app XML file: {0}".format(app_xml))

xmlfile = file(format(app_xml), 'w')

def thread_str(thread_num):
    return str('%02d' % thread_num)

print('<?xml version="1.0"?>', file=xmlfile)
print('<app>', file=xmlfile)
print('  <Objects>', file=xmlfile)
print('    <object name = \"SIMDAQ1\" class = \"SIMDAQ\"></object>', file=xmlfile)
for thread_num in range(num_threads):
    print('    <object name = \"A'+thread_str(thread_num)+'\" class = \"AnalysisThreadChain\"></object>', file=xmlfile)    
print('  </Objects>', file=xmlfile)
print('', file=xmlfile)
print('  <Links>', file=xmlfile)
for data in ['ADCOutput', 'CHAN', 'TS']:
    print('    <link writer = \"SIMDAQ1\" reader = \"A00\" data = \"'+data+'\"></link>', file=xmlfile)
for thread_id in range(1,num_threads):
    for data in ['ADCOutput', 'CHAN', 'TS']:
        print('    <link writer = \"A'+thread_str(thread_id-1)+'\" reader = \"A'+thread_str(thread_id)+'\" data = \"'+data+'\"></link>', file=xmlfile)
print('  </Links>', file=xmlfile)
print('</app>', file=xmlfile)