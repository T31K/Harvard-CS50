from flask import Flask, flash, jsonify, redirect, render_template, request, session
import requests
import json
from datetime import datetime, timedelta
import time


app = Flask(__name__)

@app.route("/")
def index():
    url = "http://datamall2.mytransport.sg/ltaodataservice/BusArrivalv2?BusStopCode=77011"

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

    ETA_NEXT_3 = datetime.strptime((response_data["Services"][1]["NextBus2"]["EstimatedArrival"]),'%Y-%m-%dT%H:%M:%S+08:00')
    ETA_NEXT_53 = datetime.strptime((response_data["Services"][5]["NextBus2"]["EstimatedArrival"]),'%Y-%m-%dT%H:%M:%S+08:00')
    ETA_NEXT_89 = datetime.strptime((response_data["Services"][7]["NextBus2"]["EstimatedArrival"]),'%Y-%m-%dT%H:%M:%S+08:00')
    ETA_NEXT_109 = datetime.strptime((response_data["Services"][0]["NextBus2"]["EstimatedArrival"]),'%Y-%m-%dT%H:%M:%S+08:00')

    ETA_list = [ETA_3,ETA_53,ETA_89,ETA_109]
    ETA_NEXT_list =[ETA_NEXT_3,ETA_NEXT_53,ETA_NEXT_89,ETA_NEXT_109]

    data = {"#3": None , "#53": None, "#89": None, "#109": None}
    data_next =  {"#3": None , "#53": None, "#89": None, "#109": None}

    for i,j in zip(ETA_list,data):
        diff = i - now_OBJ
        if len(str(diff)) == 7 and (str(diff)[2:4] != "00"):
            data[j] = str(diff)[2:4] + " mins"
        else:
            data[j] = "Arrived!"

    for a,b in zip(ETA_NEXT_list,data_next):
        diff = a - now_OBJ
        if len(str(diff)) == 7 and (str(diff)[2:4] != "00"):
            data_next[b] = str(diff)[2:4] + " mins"
        else:
            data_next[b] = "Arrived!"

    bus_3_data = data["#3"]
    bus_53_data = data["#53"]
    bus_89_data = data["#89"]
    bus_109_data = data["#109"]

    bus_3_next_data = data_next["#3"]
    bus_53_next_data = data_next["#53"]
    bus_89_next_data = data_next["#89"]
    bus_109_next_data = data_next["#109"]


    return render_template("index.html",data=data, bus_3_data=bus_3_data, bus_53_data=bus_53_data,
                                                   bus_89_data=bus_89_data,bus_109_data=bus_109_data,
                                                   bus_3_next_data=bus_3_next_data, bus_53_next_data=bus_53_next_data,
                                                   bus_89_next_data=bus_89_next_data, bus_109_next_data=bus_109_next_data)

