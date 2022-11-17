int main()
{
	int distance;
	//Send trigger pulse
	distance = getDistance();
	//Get echo time
	//Calculate distance
	if (distance <= 10)
	{
		//Display distance on 8x8 LED Matrix
	}
}

int getDistance()
{
	//Set trigger pin to high for 10 us
	//Clear trigger pin
	//Wait for echo pin to go high
	//Get start time
	//Wait for echo pin to go low
	//Get end time
	//Calculate distance
	return distance;
}
