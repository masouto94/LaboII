void celsiusAFahrenheit(){
    float celsius;
    printf("Ingrese la temperatura en grados Celsius:\n");
    std::cin >> celsius;
    float fahrenheit = (celsius * 1.8 ) + 32;
    printf("%.3f en celsius son %.3f en fahrenheit", celsius, fahrenheit );
}
