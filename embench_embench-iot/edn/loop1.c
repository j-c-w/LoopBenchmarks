void loop(short y[], const short x[], short scaler) {
	int i;
  for (i = 0; i < 150; i++)
    y[i] += ((scaler * x[i]) >> 15);
}
