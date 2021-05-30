import React, { createElement } from 'react'
import ReactDOM from 'react-dom'
import {Link} from "react-router-dom"

import Icon from '@mdi/react'
import {
  mdiRun,
  mdiYoga,
  mdiPlus,
  mdiHome,
  mdiBell,
  mdiTicket,
  mdiAccount,
  mdiArmFlex,
  mdiDumbbell,
  mdiChartLine,
  mdiChevronRight
} from '@mdi/js'

import {
  H4,
  H5,
  H6,
  Card,
  Body2,
  Caption,
  Subtitle2,
  IconButton,
  withResize,
  ToggleButton,
  ProgressCircular,
} from 'ui-neumorphism'


const myStyle = {
  width: "100%",
  display: "flex",
  alignItems: "center",
  justifyContent: "center",
  flexDirection: "column",
}


class ToDoList extends React.Component {
  constructor() {
    super();
    this.state = {value: ''};
    this.handleSubmit = this.handleSubmit.bind(this);
    this.count = 0;
  }

  handleSubmit(event) {
    // alert('A name was submitted: ' + this.state.value);
    event.preventDefault();
    const to_do_input = document.querySelector("#ToDoInput")
    if (to_do_input.value != "") {
      this.count++;
      const row = document.createElement('p');
      row.textContent = this.count + ". " + to_do_input.value;
      const list = document.querySelector("#list");
      list.appendChild(row);
      document.getElementById("ToDoInput").value = '';
    }
  }

  render() {
    return (
      <div id="list">
        <form onSubmit={this.handleSubmit} style={myStyle}>  <label>
          <H4 style={{ fontWeight: '500', marginTop: '8px' }}>ToDo</H4>
          <input type="text" id="ToDoInput" style={{marginTop: "8px", width: "100%"}}/> </label>
          <input type="submit" value="Submit"/>
        </form>
      </div>
    );

    // return (
    //   const v = this.words.map((5) => {

    //   });
    // )
  }
}


class Accaunt extends React.Component {
  render() {
    const { dark, size } = this.props
    return (
      <Card flat dark={dark} className='fitness-app-container'>
        <Card flat className='fitness-app-wrapper overflow-hidden'>
          <Card
            rounded
            width={300}
            height={600}
            className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
              } overflow-hidden`}
          >
            <H4 style={{ fontWeight: '500', marginTop: '8px' }}>Sepuh Hovhannisyan</H4>
            
            <div className='fitness-app-nav-bar'>
                <Link to="/">
                    <ToggleButton dark={dark}>
                    <Icon path={mdiHome} size={0.9} />
                    </ToggleButton>
                </Link>
                <Link to="/program">
                    <ToggleButton dark={dark}>
                    <Icon path={mdiChartLine} size={0.8} />
                    </ToggleButton>
                </Link>
                <Link to="/food">
                    <ToggleButton dark={dark}>
                    <Icon path={mdiChartLine} size={0.8} />
                    </ToggleButton>
                </Link>
                <Link to="/todo">
                    <ToggleButton dark={dark}>
                    <Icon path={mdiBell} size={0.8} />
                    </ToggleButton>
                </Link>
                <Link to="/accaunt">
                    <ToggleButton dark={dark} color='var(--primary)' selected>
                    <Icon path={mdiAccount} size={0.9} />
                    </ToggleButton>
                </Link>
            </div>
          </Card>
        </Card>
        <Body2 style={{ marginTop: '48px', textAlign: 'center' }}>
        </Body2>
      </Card>
    )
  }
}

export default withResize(Accaunt)