CS50 2020 Final Project

Bus App

This project is a simple Flask web app that displays real time bus arrival ETAs
in Singapore.

PROBLEM:
There are already plenty of such apps on the appstore/playstore.
However, I wanted a more efficient way to view bus arrival timings, rather than
checking my phone every time I wanted to check. I have an exta old iPad 2 (2011 version)
that could be set up in my living room as a full time display (much like in train stations
where you could view the timing by looking at a TV/screen).

Also, apart from old iPads have difficulty running newer iOS apps efficiently. They do not
auto refresh the timings so making it troublesome to physically press refresh every time
you needed to check the timing.

GOALS:
- Design it to fit nicely on an iPad display that runs on web browser (supported by older web browser versions)
- Auto refresh every 15 seconds
- Turn green when time is < 05 mins (enough time to get to the bus stop)

SOURCES:
The API which I used is from :
"http://datamall2.mytransport.sg/ltaodataservice/BusArrivalv2?BusStopCode=77011"

The bus code 77011 is a standardized five numerical code of all bus stops in Singapore,
by changing the value of the in application.py you can use it on any bus stops you like.

I love CS50, thank you Prof. David Malan for all the wonderful classes and challenging problem sets,
and cheers to Brian Yu of CS50 for the wonderful Flask tutorial.

