require 'mkmf'

abort 'need stdio.h' unless have_header("stdio.h")

dir_config('rb-exten')
create_makefile('rb-exten')
