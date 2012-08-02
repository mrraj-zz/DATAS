require "net/http"
require "uri"

uri = URI.parse("https://opscode-dev.chargify.com/transactions/9648413.json")

http = Net::HTTP.new(uri.host, uri.port)
request = Net::HTTP::Get.new(uri.request_uri)
request.basic_auth("mTTHZMYQZyR72g-bGkux", "x")
response = http.request(request)
puts response.inspect
