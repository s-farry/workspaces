from ROOT import *
import os

print os.sys.argv[1]
print os.listdir('/user2/sfarry/gangadir/workspace/sfarry/LocalXML/'+os.sys.argv[1])
for i in os.listdir('/user2/sfarry/gangadir/workspace/sfarry/LocalXML/'+os.sys.argv[1]):
     if os.path.isfile('/user2/sfarry/gangadir/workspace/sfarry/LocalXML/'+os.sys.argv[1]+'/'+i+'/output/ttbar.root'):
          f = TFile('/user2/sfarry/gangadir/workspace/sfarry/LocalXML/'+os.sys.argv[1]+'/'+i+'/output/ttbar.root')
          t = f.Get('ttbar/DecayTree')
          if not not t:
               if 'TTree' in t.ClassName():
                    print i,t.GetEntries('eventNumber==750662413')
