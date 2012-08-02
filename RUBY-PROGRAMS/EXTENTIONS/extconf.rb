require 'mkmf'

abort 'need stdio.h' unless have_header("stdio.h")

dir_config('test')
create_makefile('test')
