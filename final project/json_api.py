import requests
import json
from datetime import datetime, timedelta
import time

while True:
    url = "http://datamall2.mytransport.sg/ltaodataservice/BusArrivalv2?BusStopCode=78049"

    payload = {}
    headers = {'AccountKey': 'SsmusG4IRl2bt/N+BsE21A==',
                'accept': 'application/json' }
    response = requests.request("GET", url, headers=headers, data = payload)
    response_data = response.json()

    now = datetime.today() + timedelta(hours=+8)
    now_OBJ = datetime.strptime((now.strftime('%Y-%m-%d %H:%M:%S')),'%Y-%m-%d %H:%M:%S')

    ETA_3 = datetime.strptime((response_data["Services"][1]["NextBus"]["EstimatedArrival"]),'%Y-%m-%dT%H:%M:%S+08:00')
    ETA_53 = datetime.strptime((response_data["Services"][5]["NextBus"]["EstimatedArrival"]),'%Y-%m-%dT%H:%M:%S+08:00')
    ETA_89 = datetime.strptime((response_data["Services"][7]["NextBus"]["EstimatedArrival"]),'%Y-%m-%dT%H:%M:%S+08:00')
    ETA_109 = datetime.strptime((response_data["Services"][0]["NextBus"]["EstimatedArrival"]),'%Y-%m-%dT%H:%M:%S+08:00')

    ETA_list = [ETA_3,ETA_53,ETA_89,ETA_109]
    data = {"#3": None , "#53": None, "#89": None, "#109": None}

    for i,j in zip(ETA_list,data):
        diff = i - now_OBJ
        print(diff)
        #print(len(str(diff)))
        if len(str(diff)) == 7:
            if str(diff)[2] == "0" and str(diff)[3] == "0":
                data[j] = "Arrived!"
            elif str(diff)[2] != "0" and str(diff)[3] != "0":
                data[j] = str(diff)[2:4] + " mins"
            #print(str(diff)[2:4])
            else:
            #print("Arrived")
            #data[j] = (str(diff))
                data[j] = "Arrived!"
        else:
            data[j] = "Arrived!"

    bus_3_data = data["#3"]
    print(data)
    time.sleep(15)