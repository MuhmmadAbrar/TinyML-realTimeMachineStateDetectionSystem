import tensorflow as tf
from tinymlgen import port

model = tf.keras.models.load_model('./sensor.h5')

c_code = port(model, optimize=False)

with open('./realtime_predictive_maintenance/generated_code.h', 'w') as file:
    file.write(c_code)