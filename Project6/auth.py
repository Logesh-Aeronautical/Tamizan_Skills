import cv2
import mediapipe as mp
import numpy as np

mp_face = mp.solutions.face_mesh
face_mesh = mp_face.FaceMesh(static_image_mode=True)

img = cv2.imread("authorized.jpg")
rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
result = face_mesh.process(rgb)

landmarks = []
for lm in result.multi_face_landmarks[0].landmark:
    landmarks.append([lm.x, lm.y])

np.save("authorized_face.npy", np.array(landmarks))
print("Authorized face saved")
