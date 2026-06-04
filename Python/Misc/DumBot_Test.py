import requests
from fastapi import FastAPI, Request, BackgroundTasks

# ==========================================
# CONFIGURATION — Fill these in
# ==========================================
HTTPSMS_API_KEY = "uk_tDiNLOO2x1h7RfzafgKkVan94FNuUKebua-mUjv25zIVFkPJyupSUK1OO-vs9Pdf"
FROM_NUMBER     = "+639760732493"  # ← Replace with your actual Android number
FRIENDS = {
    "frenzesca a. hinayo":"Hi, mahal! I love you!",
    "gian kyle d. rapada":"Labyu, gi",
    "maren":"Maren bayot",
    "jared":"Hire me in NASA pls",
    "nathanielle":"Fuck you",
    "grace":"Hi! Traders!",
    "xeander":"chingchonglinglongbingbongfootlong 操你妈",
    "russel":"Russel V. Bayag",
    "zamir":"wassup my future McDo employer",
    "johnrev":"tanginamo lara",
    "kyx":"miss you mwa",
    "quelvin":"biob***h",
    "rion":"lmclk",
    "rhianna":"wassup sis",
    "salahadin":"adi, my goat and my king"
}

# ==========================================
# INIT
# ==========================================

app = FastAPI()

# In-memory state (resets on restart — fine for a prototype)
user_states = {}

SURVEY_QUESTIONS = {
    1: "Hello! Kindly reply with your first name (ONLY), I have a message for you. (Ex:joemarc)",
}
THANK_YOU_MSG = "Data saved successfully. Thank you for your submission!"

# ==========================================
# HELPERS
# ==========================================
def send_sms(to: str, message: str):
    try:
        response = requests.post(
            "https://api.httpsms.com/v1/messages/send",
            headers={
                "x-api-key": HTTPSMS_API_KEY,
                "Accept": "application/json",
                "Content-Type": "application/json",
            },
            json={"content": message, "from": FROM_NUMBER, "to": to},
        )
        print(f"[SMS] To {to} | Status {response.status_code}")
        print(f"[SMS Response] {response.json()}")  # ← add this line
    except Exception as e:
        print(f"[SMS Error] {e}")

def provide_response(user_text: str) -> str:
    # Logic here
    try:
        # If user response not in Friends:
        friend = user_text.strip().lower()
        response = "Hi, " + user_text + "!"

        if friend in FRIENDS.keys():
            response = FRIENDS[friend]

        return response

    except Exception as e:
        print(f"[AI Error] {e}")  # ← check what this prints
        return "System error. Please try sending your number again."


def process_sms(phone: str, text: str):
    if phone not in user_states:
        user_states[phone] = {"step": 1, "data": {}, "done": False}
        send_sms(phone, SURVEY_QUESTIONS[1])
        return

    # If user is already done, ignore
    if user_states[phone]["done"]:
        print(f"[SKIP] {phone} already completed, ignoring.")
        return

    # Step
    step = user_states[phone]["step"]

    if step > len(SURVEY_QUESTIONS):
        user_states[phone]["done"] = True
        send_sms(phone, "You have already completed the survey. Thank you!")
        return

    # Get the personalized response
    msg_response = provide_response(text)

    # Save the name
    user_states[phone]["data"][f"step_{step}"] = text.strip().lower()
    user_states[phone]["step"] += 1

    print(f"[DB] {phone} → {user_states[phone]['data']}")

    # Send the personalized message
    send_sms(phone, msg_response)


# ==========================================
# WEBHOOK
# ==========================================
@app.post("/webhook")
async def webhook(request: Request, background_tasks: BackgroundTasks):
    payload = await request.json()

    # Only process incoming messages
    event_type = payload.get("type", "")
    if event_type != "message.phone.received":
        return {"status": "ignored"}

    data  = payload.get("data", {})
    phone = data.get("contact")
    text  = data.get("content")

    if not phone or not text:
        return {"status": "error", "message": "Missing contact or content"}

    if phone == FROM_NUMBER:
        print(f"[SKIP] Message from own number, ignoring.")
        return {"status": "ignored", "message": "Own number ignored"}

    background_tasks.add_task(process_sms, phone, text)
    return {"status": "success"}