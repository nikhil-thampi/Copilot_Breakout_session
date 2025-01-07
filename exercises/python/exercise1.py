def calculate_purity(sensor_value):
    if sensor_value < 0 or sensor_value > 24:
        print("Invalid sensor value. It should be between 0 and 24 Karats.")
        return -1
    return (sensor_value / 24.0) * 100


def main():
    sensor_value = int(input("Enter the sensor value in Karats: "))
    purity = calculate_purity(sensor_value)
    if purity != -1:
        print(f"The purity of the gold is: {purity}%")


if __name__ == "__main__":
    main()
