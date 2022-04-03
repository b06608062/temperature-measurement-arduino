void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A5, INPUT);

}

void loop()
{
  float V = analogRead(A5);
  Serial.println(V);
  // 假設 V 大於544是白天
  // 啟動 TMP 偵測當前溫度
  if(V > 544){
  	float TMP = analogRead(A0);
  	// 官方公式換算
  	int T = int(((TMP * 5000 / 1024) - 500) / 10); 
  Serial.print(T);
  Serial.println("oC");
  }
  // 延遲2秒
  delay(2000);
}