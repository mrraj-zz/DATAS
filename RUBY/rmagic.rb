class Billede
require 'rubygems'
require 'RMagick'

if !ARGV[0]
    puts "Usage: watermark /image.png"
    exit
end

image = Magick::Image.read(ARGV[0]).first

mark = Magick::Image.new(image.columns, image.rows)

gc = Magick::Draw.new
gc.gravity = Magick::CenterGravity
gc.pointsize = 32
gc.font_family = "Helvetica"
gc.font_weight = Magick::BoldWeight
gc.stroke = 'none'
gc.annotate(mark, 0, 0, 0, 0, "Watermark\nby\nRMagick")

mark = mark.shade(true, 310, 30)

image.composite!(mark, Magick::CenterGravity, Magick::HardLightCompositeOp)

out = ARGV[0].sub(/\./, "-wm.")
puts "Writing #{out}"
image.write(out)
end

