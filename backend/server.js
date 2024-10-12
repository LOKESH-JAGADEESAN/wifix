// server.js
const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');

const app = express();
const PORT = process.env.PORT || 3000;

// Middleware
app.use(cors());
app.use(bodyParser.json());

// Endpoint for receiving data from ESP32
app.post('/data', (req, res) => {
  const { message } = req.body;
  console.log('Received message from ESP32:', message);
  res.json({ status: 'success', received: message });
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
