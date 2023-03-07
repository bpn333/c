int yes(){
	char c;
	printf("\n[y/n]:-");
	scanf(" %c",&c);
	if(c=='y'){
		return 1;
	}
	else if(c=='n'){
		return 0;
	}
	else{
		printf("\n\nERROR 404\n\n");
		return 0;
	}
}
