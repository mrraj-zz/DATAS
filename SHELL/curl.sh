curl 'http://localhost:9983/solr/update/json?commit=true' -H 'Content-type:application/json' -d '
{
  "add": {
    "doc": {
      "id" : "ISBN:978-0641723445",
      "title" : "The Lightning Thief"
      "author" : "Rick Riordan",
      "series_t" : "Percy Jackson and the Olympians",
      "cat" : ["book","hardcover"],
      "genre_s" : "fantasy",
      "pages_i" : 384
      "price" : 12.50,
      "inStock" : true,
      "popularity" : 10
    }
  }
}'
