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
    os.system("rm "+classes_xml_dir+"/SIMDAQ.XML")
    os.system("rm "+classes_xml_dir+"/A.XML")
    os.system("rm "+classes_xml_dir+"/B*.XML")
    os.system("rm "+classes_xml_dir+"/C.XML")
except:
    print("Unable to delete analysis thread XML files")
    sys.exit(-1)

def thread_str(thread_num):
    return str('%03d' % thread_num)

# write DAQ thread XML
class_xml = format(os.path.join(classes_xml_dir, 'SIMDAQ.XML'))
print("Writing class XML file: {0}".format(class_xml))
xmlfile = file(format(class_xml), 'w')
print('<?xml version="1.0"?>', file=xmlfile)
print('<class>', file=xmlfile)
print('  <Name name = \"SIMDAQ\" />', file=xmlfile)
print('  <Header hname = \"SIMDAQThread.h\" />', file=xmlfile)
print('  <Info cname = \"SIMDAQThread\" isdaq = \"true\" />', file=xmlfile)
print('  <DataBlocks>', file=xmlfile)
for data in ['ADCOutput', 'CHAN', 'TS']:
    print('    <Data block = \"'+data+'\" />', file=xmlfile)
print('  </DataBlocks>', file=xmlfile)
print('</class>', file=xmlfile)

# write initial thread XML
class_xml = format(os.path.join(classes_xml_dir, 'A.XML'))
print("Writing class XML file: {0}".format(class_xml))
xmlfile = file(format(class_xml), 'w')
print('<?xml version="1.0"?>', file=xmlfile)
print('<class>', file=xmlfile)
print('  <Name name = \"A\" />', file=xmlfile)
print('  <Header hname = \"AnalysisThreadInitial.h\" />', file=xmlfile)
print('  <Info cname = \"AnalysisThreadInitial\" isdaq = \"false\" />', file=xmlfile)
print('  <DataBlocks>', file=xmlfile)
for data in ['ADCOutput', 'CHAN', 'TS']:
    print('    <Data block = \"'+data+'\" />', file=xmlfile)
    for thread_id in range(num_threads):
        print('    <Data block = \"'+data+thread_str(thread_id)+'\" />', file=xmlfile)
print('  </DataBlocks>', file=xmlfile)
print('</class>', file=xmlfile)

# write final thread XML
class_xml = format(os.path.join(classes_xml_dir, 'C.XML'))
print("Writing class XML file: {0}".format(class_xml))
xmlfile = file(format(class_xml), 'w')
print('<?xml version="1.0"?>', file=xmlfile)
print('<class>', file=xmlfile)
print('  <Name name = \"C\" />', file=xmlfile)
print('  <Header hname = \"AnalysisThreadFinal.h\" />', file=xmlfile)
print('  <Info cname = \"AnalysisThreadFinal\" isdaq = \"false\" />', file=xmlfile)
print('  <DataBlocks>', file=xmlfile)
for data in ['ADCOutput', 'CHAN', 'TS']:
    print('    <Data block = \"'+data+'\" />', file=xmlfile)
    for thread_id in range(num_threads):
        print('    <Data block = \"'+data+thread_str(thread_id)+'\" />', file=xmlfile)
print('  </DataBlocks>', file=xmlfile)
print('</class>', file=xmlfile)

# write parallel thread XMLs
for thread_id in range(num_threads):
    class_xml = format(os.path.join(classes_xml_dir, 'B'+thread_str(thread_id)+'.XML'))
    print("Writing class XML file: {0}".format(class_xml))
    xmlfile = file(format(class_xml), 'w')
    print('<?xml version="1.0"?>', file=xmlfile)
    print('<class>', file=xmlfile)
    print('  <Name name = \"B'+thread_str(thread_id)+'\" />', file=xmlfile)
    print('  <Header hname = \"AnalysisThreadParallel.h\" />', file=xmlfile)
    print('  <Info cname = \"AnalysisThreadParallel\" isdaq = \"false\" />', file=xmlfile)
    print('  <DataBlocks>', file=xmlfile)
    for data in ['ADCOutput', 'CHAN', 'TS']:
        print('    <Data block = \"'+data+thread_str(thread_id)+'\" />', file=xmlfile)
    print('  </DataBlocks>', file=xmlfile)
    print('</class>', file=xmlfile)
