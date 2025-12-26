import cv2
import mediapipe as mp
import numpy as np

authorized = np.load("authorized_face.npy", allow_pickle=True)

mp_face = mp.solutions.face_mesh
face_mesh = mp_face.FaceMesh()

cap = cv2.VideoCapture(0)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    result = face_mesh.process(rgb)

    if result.multi_face_landmarks:
        landmarks = np.array(
    [[lm.x, lm.y] for lm in result.multi_face_landmarks[0].landmark],
    dtype=np.float32
)

        diff = np.mean(np.linalg.norm(authorized - landmarks, axis=1))

        if diff < 0.09:
            text = "AUTHORIZED - DOOR OPEN"
            color = (0, 255, 0)
        else:
            text = "UNAUTHORIZED - ACCESS DENIED"
            color = (0, 0, 255)

        cv2.putText(frame, text, (30, 50),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, color, 2)

    cv2.imshow("Smart Door System", frame)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
