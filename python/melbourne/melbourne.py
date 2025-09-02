import pandas as pd

melbourne_file_path = 'melbourne\melb_data.csv'

melbourne_data = pd.read_csv(melbourne_file_path)

melbourne_data.describe()