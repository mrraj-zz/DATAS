class
class DBConnection
  def initialize(conn_string)
    @conn_string = conn_string
    @connected = false
  end
  def __destroy(id)
    puts " #{id}: Closing #{@conn_string}."
  end
end

# test code
db = DBConnection.new( "Mohan" )
p db
ObjectSpace.garbage_collect
