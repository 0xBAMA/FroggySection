# FroggySection
Playing with the Lawrence Berkeley Laboratory frog cryosection/MRI dataset from 1994-1995 https://froggy.lbl.gov/ - [link to article on my site](https://jbaker.graphics/writings/froggySection.html)

This cryosection dataset is relatively unique in that they manually masked out all the major organ systems in the cryosection data. This is particularly useful due to the inconsistent lighting conditions on the sample as slices were taken. The mask files line up with the cryosection data, texel for texel, slice for slice, and demarcate areas in which you can see the major organ systems. They use 1-bit boolean masking to tell whether or not the texel is inside of the specified organ system (brain, nerves, muscles, etc).

The site describes the application of taking the place of dissection on preserved sample frogs, by allowing students to look at where the major organ systems are and how they relate to one another without having to perform the physical dissection.

NOTE: working with the data in Voraldo, I've found that there's alignment and resolution differences between the datasets - ~~There's another set of downsampled images of the cryosection slices that should line up, but I haven't gotten it together yet.~~ After figuring out that the file in the archive is grayscale instead of color, I unpacked the raw file into png slices and found this:

https://user-images.githubusercontent.com/43890665/163740270-afbbb5a2-76c9-470f-a093-c579485db220.mp4

As far as I'm concerned, I don't think the data is easily recoverable. The filesize (kind of) matches the description in the associated readme, except the number of bytes in the file is only enough for single channel data (exactly enough, no header) instead of the three channel specified by the readme, and the contents of the archived data are badly distorted.

If you wish to do something with the data, I recommend just using the masks, which are consistent with each other and work for false color renderings like the following:


Bones and Muscles masks
<img src="Voraldo Example/muscle_bone.png">

Bones, Nerves, and Blood masks
<img src="Voraldo Example/bones_nerves_blood.png">
