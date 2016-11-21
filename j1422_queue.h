//カウントを使ったリングバッファのキュー
Q_type Q[Q_size];
int f, r, count;//f:データの先頭　r:データの末尾　count:キューのデータ数

void init_Q()//キューの初期化
{
	f = count = 0;
	r = -1;
}

//キューにデータを格納する関数
void enqueue(Q_type d)
{
	if(count < Q_size)//カウント(データの数)がキューの最大より小さい
	{
		r++;//末尾を+１
		if(r == Q_size){//データ数が満タンだったら
			r = 0;//0にする
		}
		Q[r]= d;//r番目に格納
		count++;//データの数を+1
	}
  else
  {
    fprintf(stderr, "Error : queue is full \n");//キューがいっぱい
    exit(1);
  }
}

//キューのデータを取り出す
Q_type dequeue(){
  int i = 0;
  if(count > 0)//データが入っていたら
  {
    i = f;
    f++;
    if(f == Q_size)//データの先頭がサイズまできたら
    {
      f = 0;
    }
    count--;//取り出すので-1
    return Q[i];//値を返す
  }
  else
  {
      fprintf(stderr, "Error : queue is empty \n");//キューが空
      exit(1);
  }
}
