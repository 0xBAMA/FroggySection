# FroggySection
Playing with the Lawrence Berkeley Laboratory frog cryosection/MRI dataset from 1994-1995 https://froggy.lbl.gov/

This cryosection dataset is relatively unique in that they manually masked out all the major organ systems in the cryosection data. This is particularly useful due to the inconsistent lighting conditions on the sample as slices were taken. The mask files line up with the cryosection data, texel for texel, slice for slice, and demarcate areas in which you can see the major organ systems. The use 1-bit boolean masking to tell whether the texel is inside of the given organ system or not.

The site describes the application of taking the place of dissection on preserved sample frogs, by allowing students to look at where the major organ systems are and how they relate to one another without having to do the physical dissection.
