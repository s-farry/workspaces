exe=/user2/sfarry/workspaces/strange/apply_bdt
tuples="dpm/strange/ZMuMuJet.MU.2012.root dpm/strange/ZMuMuJet.MD.2012.root dpm/strange/Zmumujet.Z_mumujet17.MD.MC2012.root dpm/strange/Zmumujet.Z_mumujet17.MU.MC2015.root dpm/strange/Zmumujet.Z_mumujet17.MD.MC2015.root dpm/strange/Zmumujet.Z_mumujet17.MU.MC2012.root /user2/sfarry/workspaces/strange/tuples/jet.dijet*MC2015.root"
tuples="/user2/sfarry/workspaces/strange/tuples/jet.dijet*MC2015*root"
for t in $tuples; do $exe $t; done