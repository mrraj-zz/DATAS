
#!/usr/bin/env ruby
# 
# A crude image comparison tool.
# 
# Usage:
# vdiff original_image modified_image
 
require "rubygems"
require "RMagick"
 
original = Magick::Image.read(ARGV[0]).first
new_version = Magick::Image.read(ARGV[1]).first
comparison = original.composite(new_version, Magick::CenterGravity, Magick::DifferenceCompositeOp)
comparison.write("diff.png")
