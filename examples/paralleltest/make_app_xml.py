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
    return str('%03d' % thread_num)

print('<?xml version="1.0"?>', file=xmlfile)
print('<app>', file=xmlfile)
print('  <Objects>', file=xmlfile)
print('    <object name = \"SIMDAQ\" class = \"SIMDAQThread\"></object>', file=xmlfile)
print('    <object name = \"A\" class = \"AnalysisThreadInitial\"></object>', file=xmlfile)
for thread_id in range(num_threads):
    print('    <object name = \"B'+thread_str(thread_id)+'\" class = \"AnalysisThreadSeries\"></object>', file=xmlfile)    
print('    <object name = \"C\" class = \"AnalysisThreadFinal\"></object>', file=xmlfile)
print('  </Objects>', file=xmlfile)
print('', file=xmlfile)
print('  <Links>', file=xmlfile)
for data in ['ADCOutput', 'CHAN', 'TS']:
    print('    <link writer = \"SIMDAQ\" reader = \"A\" data = \"'+data+'\"></link>', file=xmlfile)
for thread_id in range(num_threads):
    for data in ['ADCOutput', 'CHAN', 'TS']:
        print('    <link writer = \"A\" reader = \"B'+thread_str(thread_id)+'\" data = \"'+data+thread_str(thread_id)+'\"></link>', file=xmlfile)
for thread_id in range(num_threads):
    for data in ['ADCOutput', 'CHAN', 'TS']:
        print('    <link writer = \"B'+thread_str(thread_id)+'\" reader = \"C\" data = \"'+data+thread_str(thread_id)+'\"></link>', file=xmlfile)
print('  </Links>', file=xmlfile)
print('</app>', file=xmlfile)