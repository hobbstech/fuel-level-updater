
void updateLevel(double petrolLevel, double dieselLevel){
  String url = "https://fuel-station-locator.herokuapp.com/v1/fuel-level";
  String payload = "{ \"petrolLevel\" : ";
  payload.concat(petrolLevel);
  payload.concat(",");
  payload.concat("\"dieselLevel\" : ");
  payload.concat(dieselLevel);
  payload.concat("}");
  doHttpCall(url, payload, 1);
}
