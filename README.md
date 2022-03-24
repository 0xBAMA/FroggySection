# FroggySection
Playing with the Lawrence Berkeley Laboratory frog cryosection/MRI dataset from 1994-1995 https://froggy.lbl.gov/

This cryosection dataset is relatively unique in that they manually masked out all the major organ systems in the cryosection data. This is particularly useful due to the inconsistent lighting conditions on the sample as slices were taken. The mask files line up with the cryosection data, texel for texel, slice for slice, and demarcate areas in which you can see the major organ systems. They use 1-bit boolean masking to tell whether or not the texel is inside of the specified organ system (brain, nerves, muscles, etc).

The site describes the application of taking the place of dissection on preserved sample frogs, by allowing students to look at where the major organ systems are and how they relate to one another without having to perform the physical dissection.

NOTE: working with the data in Voraldo, I've found that there's alignment and resolution differences between the datasets - There's another set of downsampled images of the cryosection slices that should line up, but I haven't gotten it together yet. The masks are consistent with each other, and work for false color renderings like these:


Bones and Muscles masks
<img src="example/muscle_bone.png">

Bones, Nerves, and Blood masks
<img src="example/bones_nerves_blood.png">
